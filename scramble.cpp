#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2/SDL_audio.h>
#include <iostream>
#include <cmath>

#include "Vmcu.h"
#include "verilated.h"

#if VM_TRACE
# include <verilated_vcd_c.h>
#endif


SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* canvas;
SDL_Surface* background;
SDL_Surface* images[22];

float freq = 0;
const int rate = 96000;
Sint16 sbuf[4096];
int sbuf_i = 0;

Vmcu* mcu;

static int events(int clk)
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button) {
          case SDL_BUTTON_LEFT:
            mcu->prtAI = 0b1110;
            break;
          case SDL_BUTTON_RIGHT:
            mcu->prtBI = 0b1101;
            break;
          case SDL_BUTTON_MIDDLE:
            mcu->prtBI = 0b1110;
            break;
        }
        break;
      case SDL_MOUSEBUTTONUP:
        mcu->prtAI &= 1;
        mcu->prtBI = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_SPACE:
          case SDLK_RETURN:
            mcu->prtAI = 0b1110;
            break;
          case SDLK_UP:
            mcu->prtBI = 0b1101;
            break;
          case SDLK_DOWN:
            mcu->prtBI = 0b1110;
            break;
        }
        break;
      case SDL_KEYUP:
        mcu->prtAI = 0;
        mcu->prtBI = 0b1100;
        break;
      case SDL_QUIT:
        SDL_FreeSurface(screen);
        SDL_DestroyWindow(window);
        SDL_Quit();
        printf("evaluated: %d\n", clk);
        return 1;
    }
  }
  return 0;
}

static void set_plate(int g, int p, int v) {
  if (v != 0) {
    int id = 99;
    SDL_Rect dst;

    if (g == 0) {
      switch (p) {
        case 0:
          id = 0; dst.x = 16; dst.y = 12;
          break;
        case 1:
          id = 1; dst.x = 12; dst.y = 29;
          break;
        case 2:
          id = 0; dst.x = 16; dst.y = 57;
          break;
        case 3:
          id = 1; dst.x = 12; dst.y = 74;
          break;
        case 4:
          id = 0; dst.x = 16; dst.y = 101;
          break;
        case 5:
          id = 1; dst.x = 12; dst.y = 118;
          break;
        case 6:
          id = 0; dst.x = 16; dst.y = 147;
          break;
        case 7:
          id = 1; dst.x = 12; dst.y = 164;
          break;
        case 8:
          id = 2; dst.x = 35; dst.y = 147;
          break;
        case 9:
          id = 4; dst.x = 43; dst.y = 161;
          break;
        case 10:
          id = 5; dst.x = 40; dst.y = 182;
          break;
        case 11:
          id = 3; dst.x = 35; dst.y = 101;
          break;
        case 12:
          id = 4; dst.x = 43; dst.y = 115;
          break;
        case 13:
          id = 3; dst.x = 35; dst.y = 57;
          break;
        case 14:
          id = 4; dst.x = 43; dst.y = 71;
          break;
        case 15:
          id = 3; dst.x = 35; dst.y = 12;
          break;
        case 16:
          id = 4; dst.x = 43; dst.y = 26;
          break;
      }
    }

    else if (g <= 7) {
      switch (p) {
        case 0:
          id = 8; dst.x = 39 + 58*g; dst.y = 15;
          break;
        case 1:
          id = 10; dst.x = 39 + 58*g; dst.y = 16;
          break;
        case 2:
          id = 8; dst.x = 39 + 58*g; dst.y = 60;
          break;
        case 3:
          id = 10; dst.x = 39 + 58*g; dst.y = 61;
          break;
        case 4:
          id = 8; dst.x = 39 + 58*g; dst.y = 104;
          break;
        case 5:
          id = 10; dst.x = 39 + 58*g; dst.y = 105;
          break;
        case 6:
          id = 8; dst.x = 39 + 58*g; dst.y = 150;
          break;
        case 7:
          id = 10; dst.x = 39 + 58*g; dst.y = 151;
          break;
        case 8:
          id = 7; dst.x = 35 + 58*g; dst.y = 147;
          break;
        case 9:
          id = 9; dst.x = 48 + 58*g; dst.y = 161;
          break;
        case 10:
          id = 11; dst.x = 40 + 58*g; dst.y = 184;
          break;
        case 11:
          id = 6; dst.x = 35 + 58*g; dst.y = 101;
          break;
        case 12:
          id = 9; dst.x = 48 + 58*g; dst.y = 115;
          break;
        case 13:
          id = 6; dst.x = 35 + 58*g; dst.y = 57;
          break;
        case 14:
          id = 9; dst.x = 48 + 58*g; dst.y = 71;
          break;
        case 15:
          id = 6; dst.x = 35 + 58*g; dst.y = 12;
          break;
        case 16:
          id = 9; dst.x = 48 + 58*g; dst.y = 26;
          break;
      }
    }

    // 10 plates only
    else if (g == 8) {
      switch (p) {
        case 0:
          id = 15; dst.x = 533; dst.y = 13;
          break;
        case 1:
          id = 16; dst.x = 548; dst.y = 16;
          break;
        case 2:
          id = 17; dst.x = 530; dst.y = 16;
          break;
        case 3:
          id = 18; dst.x = 534; dst.y = 30;
          break;
        case 4:
          id = 16; dst.x = 548; dst.y = 32;
          break;
        case 5:
          id = 17; dst.x = 530; dst.y = 32;
          break;
        case 6:
          id = 19; dst.x = 533; dst.y = 46;
          break;
        case 7:
          id = 14; dst.x = 518; dst.y = 16;
          break;
        case 8:
          id = 12; dst.x = 499; dst.y = 59;
          break;
        case 9:
          id = 13; dst.x = 499; dst.y = 79;
          break;
      }
    }

    // no plate #10
    else if (g == 9) {
      switch (p) {
        case 0:
          id = 15; dst.x = 576; dst.y = 13;
          break;
        case 1:
          id = 16; dst.x = 591; dst.y = 16;
          break;
        case 2:
          id = 17; dst.x = 573; dst.y = 16;
          break;
        case 3:
          id = 18; dst.x = 577; dst.y = 30;
          break;
        case 4:
          id = 16; dst.x = 591; dst.y = 32;
          break;
        case 5:
          id = 17; dst.x = 573; dst.y = 32;
          break;
        case 6:
          id = 19; dst.x = 576; dst.y = 46;
          break;
        case 7:
          id = 20; dst.x = 603; dst.y = 13;
          break;
        case 8:
          id = 21; dst.x = 578; dst.y = 68;
          break;
        case 9:
          id = 21; dst.x = 578; dst.y = 83;
          break;
        case 11:
          id = 21; dst.x = 578; dst.y = 98;
          break;
        case 12:
          id = 21; dst.x = 578; dst.y = 113;
          break;
        case 13:
          id = 21; dst.x = 578; dst.y = 128;
          break;
        case 14:
          id = 21; dst.x = 578; dst.y = 143;
          break;
        case 15:
          id = 21; dst.x = 578; dst.y = 158;
          break;
        case 16:
          id = 21; dst.x = 578; dst.y = 173;
          break;
      }
    }

    if (id != 99)
      SDL_BlitSurface(images[id], NULL, canvas, &dst);
  }
}


SDL_Surface* load_png(const char* path) {
  SDL_Surface* surf;
  SDL_Surface* png = IMG_Load((char*)path);
  surf = SDL_ConvertSurface(png, canvas->format, 0);
  SDL_FreeSurface(png);
  return surf;
}


void audio_callback(void *userdata, Uint8 *_stream, int len) {
  Sint16 *stream = (Sint16*) _stream;
  len /= 2;
  for (int i = 0; i < len; ++i) {
    stream[i] = sbuf[i];
  }
  sbuf_i = 0;
}


int main(int argc, char** argv, char** env) {

  window = SDL_CreateWindow(
    "Scramble",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640, 200,
    SDL_WINDOW_OPENGL
  );

  screen = SDL_GetWindowSurface(window);
  canvas = SDL_CreateRGBSurfaceWithFormat(0, 640, 200, 32, SDL_PIXELFORMAT_RGBA32);

  IMG_Init(IMG_INIT_PNG);
  background = load_png("VFD/scramble/background.png");
  images[0] = load_png("VFD/scramble/g0-0-2-4-6.png");
  images[1] = load_png("VFD/scramble/g0-1-3-5-7.png");
  images[2] = load_png("VFD/scramble/g0-8.png");
  images[3] = load_png("VFD/scramble/g0-11-13-15.png");
  images[4] = load_png("VFD/scramble/g0-9-12-14-16.png");
  images[5] = load_png("VFD/scramble/g0-10.png");

  images[6] = load_png("VFD/scramble/g1-11-13-15.png");
  images[7] = load_png("VFD/scramble/g1-8.png");
  images[8] = load_png("VFD/scramble/g1-0-2-4-6.png");
  images[9] = load_png("VFD/scramble/g1-9-12-14-16.png");
  images[10] = load_png("VFD/scramble/g1-1-3-5-7.png");
  images[11] = load_png("VFD/scramble/g1-10.png");

  images[12] = load_png("VFD/scramble/g8-8.png");
  images[13] = load_png("VFD/scramble/g8-9.png");
  images[14] = load_png("VFD/scramble/g8-7.png");
  images[15] = load_png("VFD/scramble/g8-0.png");
  images[16] = load_png("VFD/scramble/g8-1-4.png");
  images[17] = load_png("VFD/scramble/g8-2-5.png");
  images[18] = load_png("VFD/scramble/g8-3.png");
  images[19] = load_png("VFD/scramble/g8-6.png");

  images[20] = load_png("VFD/scramble/g9-7.png");
  images[21] = load_png("VFD/scramble/g9-8--16.png");

  SDL_AudioSpec spec;
  spec.freq = rate;
  spec.format = AUDIO_S16SYS;
  spec.channels = 1;
  spec.samples = 2048;
  spec.callback = audio_callback;
  spec.userdata = nullptr;
  SDL_AudioSpec obtainedSpec;
  SDL_OpenAudio(&spec, &obtainedSpec);
  SDL_PauseAudio(0);

  Verilated::commandArgs(argc, argv);
  mcu = new Vmcu;

  #if VM_TRACE			// If verilator was invoked with --trace
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    mcu->trace(tfp, 99);
    tfp->open("dump.vcd");	// Open the dump file
  #endif

  int cycles = 0;

  mcu->reset = 1;
  while (cycles < 500) {
    mcu->clk = !mcu->clk;
    mcu->eval();
    #if VM_TRACE
	    if (tfp) tfp->dump(cycles);
    #endif
    if (mcu->clk) cycles++;
  }
  mcu->reset = 0;

  int prtC = mcu->prtC;
  int prtD = mcu->prtD;
  int prtE = mcu->prtE;
  int prtF = mcu->prtF;
  int prtG = mcu->prtG;
  int prtH = mcu->prtH;
  int prtI = mcu->prtI;

  int vfd_cycles = 0;
  while (true) {

    if (mcu->prtC != prtC ||
        mcu->prtD != prtD ||
        mcu->prtE != prtE ||
        mcu->prtF != prtF ||
        mcu->prtG != prtG ||
        mcu->prtH != prtH ||
        mcu->prtI != prtI) {

      prtC = mcu->prtC;
      prtD = mcu->prtD;
      prtE = mcu->prtE;
      prtF = mcu->prtF;
      prtG = mcu->prtG;
      prtH = mcu->prtH;
      prtI = mcu->prtI;

      int grids = ((prtI & 0b11) << 8) | ((prtD & 0b1111) << 4) | (prtC & 0b1111);

      for (int g = 9; g >= 0; g--) {
        int grid_bit = grids & (1 << g);
        if (grid_bit != 0) {
          set_plate(g, 0, mcu->prtF & 0b1000);
          set_plate(g, 1, mcu->prtG & 0b1000);
          set_plate(g, 2, mcu->prtF & 0b0100);
          set_plate(g, 3, mcu->prtG & 0b0100);
          set_plate(g, 4, mcu->prtF & 0b0010);
          set_plate(g, 5, mcu->prtG & 0b0010);
          set_plate(g, 6, mcu->prtF & 0b0001);
          set_plate(g, 7, mcu->prtG & 0b0001);
          set_plate(g, 8, mcu->prtH & 0b0001);
          set_plate(g, 9, mcu->prtE & 0b0001);
          set_plate(g, 10, 1);
          set_plate(g, 11, mcu->prtH & 0b0010);
          set_plate(g, 12, mcu->prtE & 0b0010);
          set_plate(g, 13, mcu->prtH & 0b0100);
          set_plate(g, 14, mcu->prtE & 0b0100);
          set_plate(g, 15, mcu->prtH & 0b1000);
          set_plate(g, 16, mcu->prtE & 0b1000);
        }
      }
    }

    if (vfd_cycles > 20000) {
      vfd_cycles = 0;
      SDL_BlitSurface(canvas, NULL, screen, NULL);
      SDL_UpdateWindowSurface(window);
      SDL_BlitSurface(background, NULL, canvas, NULL);
    }
    vfd_cycles++;


    if (events(cycles)) break;

    mcu->eval();

    #if VM_TRACE
      if (tfp) tfp->dump(cycles);
    #endif

    mcu->clk = !mcu->clk;
    if (mcu->clk) cycles++;

    if (mcu->clk) {
      sbuf[sbuf_i] = mcu->prtI & 0b100 ? ((1<<15)-1) : 0;
      sbuf_i++;
    }

  }

  #if VM_TRACE
    if (tfp) tfp->close();
  #endif

  return 0;
}