Nec uCom-43 MCU
---

A Verilog implementation of the Nec uCom-43 4-bit microcontroller from 1978.

I was able to synthesize it on a Spartan-6 board without too much trouble: the compiler complained about 8 unconnected signals but those are the output signals for the two A & B ports that are inputs only, and I didn't want to complicate things. The core was also tested with Verilator and connected to an emulated VFD to play Tomy Scramble (D553C192) and Epoch Galaxy II.

![Preview](./preview.apng)

About the ALU, I'm still not sure how it is possible to increment a 4-bit register while the ALU is XORing the two lower bits of DPH. I think there is an independant XOR circuitry for DPH only.

Use `make scramble` to create the Tomy Scramble simulation or `make galaxy` to generate Epoch Galaxy II. Then `./obj_dir/Vmcu` to play the game!

