Nec uCom-43 MCU
---

A Verilog implementation of the Nec uCom-43 4-bit microcontroller from 1978. I wanted to start with something simple for my very first Verilog core. I was able to synthesize it on a Spartan-6 board without too much trouble: the compiler complained about 8 unconnected signals but those are the output signals for the two A & B ports that are inputs only, and I didn't want to complicate things. The core was also tested with Verilator and connected to an emulated VFD to play Tomy Scramble (D553C192). About the ALU, I'm still not sure how it is possible to increment a 4-bit register while the ALU is XORing the two lower bits of DPH. I think there is an independant XOR circuitry for DPH only. I also had problems to figure out what is the correct port order for the OCD instruction. In the official documentation (`uCOM-43_SINGLE_CHIP_MICROCOMPUTER_USERS_MANUAL.pdf`), the C port contains the 4 upper bits: C,D ← I7...I0, but I had to reverse the VFD connections to make it work properly with Tomy Scramble.


License
---

```
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
 
If you happen to meet one of the copyright holders in a bar you are obligated
to buy them one pint of beer.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
