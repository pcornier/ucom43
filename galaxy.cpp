#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Vmcu.h"
#include "verilated.h"

#if VM_TRACE
# include <verilated_vcd_c.h>
#endif


SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* canvas;
SDL_Surface* background;
SDL_Surface* images[28];

Vmcu* mcu;

static int events(int clk)
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button) {
          case SDL_BUTTON_LEFT:
            mcu->prtAI |= 0b0001;
            mcu->prtBI |= 0b0010;
            break;
          case SDL_BUTTON_RIGHT:
            mcu->prtAI |= 0b0010;
            break;
          case SDL_BUTTON_MIDDLE:
            mcu->prtAI |= 0b0100;
            break;
        }
        break;
      case SDL_MOUSEBUTTONUP:
        mcu->prtAI = 0;
        mcu->prtBI = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_SPACE:
          case SDLK_RETURN:
            mcu->prtAI |= 0b0001;
            break;
          case SDLK_LEFT:
            mcu->prtAI |= 0b0010;
            break;
          case SDLK_RIGHT:
            mcu->prtAI |= 0b0100;
            break;
        }
        break;
      case SDL_KEYUP:
        mcu->prtAI = 0;
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
          id = 10; dst.x = 105; dst.y = 74;
          break;
        case 1:
          id = 11; dst.x = 82; dst.y = 72;
          break;
        case 2:
          id = 12; dst.x = 79; dst.y = 74;
          break;
        case 3:
          id = 13; dst.x = 86; dst.y = 92;
          break;
        case 4:
          id = 14; dst.x = 79; dst.y = 99;
          break;
        case 6:
          id = 16; dst.x = 105; dst.y = 98;
          break;
        case 7:
          id = 15; dst.x = 83; dst.y = 117;
          break;
        case 8:
          id = 11; dst.x = 33; dst.y = 72;
          break;
        case 9:
          id = 14; dst.x = 30; dst.y = 99;
          break;
        case 10:
          id = 12; dst.x = 30; dst.y = 74;
          break;
        case 11:
          id = 10; dst.x = 55; dst.y = 73;
          break;
        case 12:
          id = 13; dst.x = 37; dst.y = 92;
          break;
        case 13:
          id = 16; dst.x = 55; dst.y = 98;
          break;
        case 14:
          id = 15; dst.x = 34; dst.y = 118;
          break;
      }
    }

    else if (g == 1) {
      switch (p) {
        case 0:
          id = 10; dst.x = 213; dst.y = 74;
          break;
        case 1:
          id = 11; dst.x = 192; dst.y = 72;
          break;
        case 2:
          id = 12; dst.x = 189; dst.y = 74;
          break;
        case 3:
          id = 13; dst.x = 196; dst.y = 92;
          break;
        case 4:
          id = 14; dst.x = 189; dst.y = 99;
          break;
        case 6:
          id = 16; dst.x = 213; dst.y = 98;
          break;
        case 7:
          id = 15; dst.x = 192; dst.y = 117;
          break;
        case 8:
          id = 11; dst.x = 142; dst.y = 72;
          break;
        case 9:
          id = 14; dst.x = 139; dst.y = 99;
          break;
        case 10:
          id = 12; dst.x = 139; dst.y = 74;
          break;
        case 11:
          id = 10; dst.x = 164; dst.y = 73;
          break;
        case 12:
          id = 13; dst.x = 146; dst.y = 92;
          break;
        case 13:
          id = 16; dst.x = 164; dst.y = 98;
          break;
        case 14:
          id = 15; dst.x = 142; dst.y = 118;
          break;
      }
    }

    else if (g == 2) {
      switch (p) {
        case 0:
          id = 27; dst.x = 161; dst.y = 210;
          break;
        case 1:
          id = 27; dst.x = 200; dst.y = 210;
          break;
        case 2:
          id = 9; dst.x = 27; dst.y = 221;
          break;
        case 3:
          id = 0; dst.x = 29; dst.y = 175;
          break;
        case 4:
          id = 27; dst.x = 41; dst.y = 210;
          break;
        case 5:
          id = 1; dst.x = 66; dst.y = 221;
          break;
        case 6:
          id = 27; dst.x = 120; dst.y = 210;
          break;
        case 7:
          id = 27; dst.x = 81; dst.y = 210;
          break;
        case 8:
          id = 0; dst.x = 187; dst.y = 175;
          break;
        case 9:
          id = 9; dst.x = 186; dst.y = 221;
          break;
        case 10:
          id = 1; dst.x = 146; dst.y = 221;
          break;
        case 11:
          id = 0; dst.x = 148; dst.y = 175;
          break;
        case 12:
          id = 9; dst.x = 107; dst.y = 221;
          break;
        case 13:
          id = 0; dst.x = 108; dst.y = 175;
          break;
        case 14:
          id = 0; dst.x = 69; dst.y = 175;
          break;
      }
    }

    else if (g == 3) {
      switch (p) {
        case 0:
          id = 26; dst.x = 161; dst.y = 331;
          break;
        case 1:
          id = 26; dst.x = 200; dst.y = 331;
          break;
        case 2:
          id = 1; dst.x = 27; dst.y = 294;
          break;
        case 3:
          id = 26; dst.x = 42; dst.y = 279;
          break;
        case 4:
          id = 26; dst.x = 41; dst.y = 331;
          break;
        case 5:
          id = 9; dst.x = 66; dst.y = 294;
          break;
        case 6:
          id = 26; dst.x = 120; dst.y = 331;
          break;
        case 7:
          id = 26; dst.x = 81; dst.y = 331;
          break;
        case 8:
          id = 26; dst.x = 200; dst.y = 279;
          break;
        case 9:
          id = 1; dst.x = 186; dst.y = 294;
          break;
        case 10:
          id = 9; dst.x = 146; dst.y = 294;
          break;
        case 11:
          id = 26; dst.x = 160; dst.y = 279;
          break;
        case 12:
          id = 1; dst.x = 106; dst.y = 294;
          break;
        case 13:
          id = 26; dst.x = 121; dst.y = 279;
          break;
        case 14:
          id = 26; dst.x = 81; dst.y = 279;
          break;
      }
    }

    else if (g <= 8) {
      switch (p) {
        case 0:
          id = 25; dst.x = 159; dst.y = 402 + (g-4) * 74;
          break;
        case 1:
          id = 25; dst.x = 200; dst.y = 402 + (g-4) * 74;
          break;
        case 2:
          id = 19; dst.x = 33; dst.y = 364 + (g-4) * 74;
          break;
        case 3:
          id = 2; dst.x = 22; dst.y = 363 + (g-4) * 74;
          break;
        case 4:
          id = 25; dst.x = 40; dst.y = 402 + (g-4) * 74;
          break;
        case 5:
          id = 20; dst.x = 75; dst.y = 364 + (g-4) * 74;
          break;
        case 6:
          id = 25; dst.x = 119; dst.y = 402 + (g-4) * 74;
          break;
        case 7:
          id = 25; dst.x = 80; dst.y = 402 + (g-4) * 74;
          break;
        case 8:
          id = 6; dst.x = 183; dst.y = 363 + (g-4) * 74;
          break;
        case 9:
          id = 18; dst.x = 191; dst.y = 364 + (g-4) * 74;
          break;
        case 10:
          id = 21; dst.x = 153; dst.y = 364 + (g-4) * 74;
          break;
        case 11:
          id = 5; dst.x = 145; dst.y = 363 + (g-4) * 74;
          break;
        case 12:
          id = 22; dst.x = 116; dst.y = 364 + (g-4) * 74;
          break;
        case 13:
          id = 4; dst.x = 104; dst.y = 363 + (g-4) * 74;
          break;
        case 14:
          id = 3; dst.x = 64; dst.y = 363 + (g-4) * 74;
          break;
      }
    }


    else if (g == 9) {
      switch (p) {
        case 0:
          id = 24; dst.x = 143; dst.y = 771;
          break;
        case 1:
          id = 24; dst.x = 183; dst.y = 771;
          break;
        case 2:
          id = 23; dst.x = 34; dst.y = 739;
          break;
        case 3:
          id = 7; dst.x = 25; dst.y = 739;
          break;
        case 4:
          id = 24; dst.x = 24; dst.y = 771;
          break;
        case 5:
          id = 23; dst.x = 72; dst.y = 739;
          break;
        case 6:
          id = 24; dst.x = 104; dst.y = 771;
          break;
        case 7:
          id = 24; dst.x = 64; dst.y = 771;
          break;
        case 8:
          id = 7; dst.x = 183; dst.y = 739;
          break;
        case 9:
          id = 23; dst.x = 192; dst.y = 739;
          break;
        case 10:
          id = 23; dst.x = 152; dst.y = 739;
          break;
        case 11:
          id = 8; dst.x = 141; dst.y = 739;
          break;
        case 12:
          id = 23; dst.x = 112; dst.y = 739;
          break;
        case 13:
          id = 7; dst.x = 103; dst.y = 739;
          break;
        case 14:
          id = 8; dst.x = 62; dst.y = 739;
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

int main(int argc, char** argv, char** env) {

  window = SDL_CreateWindow(
    "Galaxy",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    248, 875,
    SDL_WINDOW_OPENGL
  );

  screen = SDL_GetWindowSurface(window);
  canvas = SDL_CreateRGBSurfaceWithFormat(0, 248, 875, 32, SDL_PIXELFORMAT_RGBA32);

  IMG_Init(IMG_INIT_PNG);
  background = load_png("VFD/galaxy/background.png");
  images[0] = load_png("VFD/galaxy/g888.png");
  images[1] = load_png("VFD/galaxy/g327.png");
  images[2] = load_png("VFD/galaxy/g922.png");
  images[3] = load_png("VFD/galaxy/g928.png");
  images[4] = load_png("VFD/galaxy/g934.png");
  images[5] = load_png("VFD/galaxy/g940.png");
  images[6] = load_png("VFD/galaxy/g946.png");
  images[7] = load_png("VFD/galaxy/g952.png");
  images[8] = load_png("VFD/galaxy/g958.png");
  images[9] = load_png("VFD/galaxy/g306.png");

  images[10] = load_png("VFD/galaxy/path20078-8.png");
  images[11] = load_png("VFD/galaxy/path20080-0.png");
  images[12] = load_png("VFD/galaxy/path20082-05.png");
  images[13] = load_png("VFD/galaxy/path20084-0.png");
  images[14] = load_png("VFD/galaxy/path20086-4.png");
  images[15] = load_png("VFD/galaxy/path20088-4.png");
  images[16] = load_png("VFD/galaxy/path20090-95.png");

  //images[17] = load_png("VFD/galaxy/g6007.png");
  images[18] = load_png("VFD/galaxy/path21017-1.png");
  images[19] = load_png("VFD/galaxy/path21017-3.png");
  images[20] = load_png("VFD/galaxy/path21017-7.png");
  images[21] = load_png("VFD/galaxy/path21017-8.png");
  images[22] = load_png("VFD/galaxy/path21017.png");
  images[23] = load_png("VFD/galaxy/path22207-7-6.png");
  images[24] = load_png("VFD/galaxy/path22209-6-1.png");
  images[25] = load_png("VFD/galaxy/rect20238-9-5-2-6-4-9.png");
  images[26] = load_png("VFD/galaxy/rect20238-9-57-3.png");
  images[27] = load_png("VFD/galaxy/rect20238.png");

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

      // int grids = 0b1111111111;
      int grids =
        (prtC & 0b0001 ? 0b1000000000 : 0) |
        (prtC & 0b0010 ? 0b0100000000 : 0) |
        (prtC & 0b0100 ? 0b0010000000 : 0) |
        (prtC & 0b1000 ? 0b0001000000 : 0) |
        (prtD & 0b0001 ? 0b0000100000 : 0) |
        (prtD & 0b0010 ? 0b0000010000 : 0) |
        (prtD & 0b0100 ? 0b0000001000 : 0) |
        (prtD & 0b1000 ? 0b0000000100 : 0) |
        (prtE & 0b0001 ? 0b0000000010 : 0) |
        (prtE & 0b0010 ? 0b0000000001 : 0);

      for (int g = 9; g >= 0; g--) {
        int grid_bit = grids & (1 << g);
        if (grid_bit != 0) {

          // set_plate(g,  8, 1);
          // set_plate(g, 11, 1);
          // set_plate(g, 13, 1);
          // set_plate(g, 14, 1);

          // set_plate(g,  9,  1);
          // set_plate(g, 10,  1);
          // set_plate(g, 12,  1);
          // set_plate(g,  5,  1);

          // set_plate(g,  1,  1);
          // set_plate(g,  0,  1);
          // set_plate(g,  6,  1);
          // set_plate(g,  7,  1);

          // set_plate(g,  4,  1);
          // set_plate(g,  2,  1);
          // set_plate(g,  3,  1);

          set_plate(g,  8, prtF & 0b0001);
          set_plate(g, 11, prtF & 0b0010);
          set_plate(g, 13, prtF & 0b0100);
          set_plate(g, 14, prtF & 0b1000);

          set_plate(g,  9, prtG & 0b0001);
          set_plate(g, 10, prtG & 0b0010);
          set_plate(g, 12, prtG & 0b0100);
          set_plate(g,  5, prtG & 0b1000);

          set_plate(g,  1, prtH & 0b0001);
          set_plate(g,  0, prtH & 0b0010);
          set_plate(g,  6, prtH & 0b0100);
          set_plate(g,  7, prtH & 0b1000);

          set_plate(g,  4, prtI & 0b001);
          set_plate(g,  2, prtI & 0b010);
          set_plate(g,  3, prtI & 0b100);

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

  }

  #if VM_TRACE
    if (tfp) tfp->close();
  #endif

  return 0;
}