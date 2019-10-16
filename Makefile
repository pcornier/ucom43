
.PHONY: scramble

scramble:
	rm -rf ./obj_dir
	verilator -Wall --cc mcu.v --exe scramble.cpp -CFLAGS -I/usr/include/SDL2 -CFLAGS -g -LDFLAGS -lSDL2 -LDFLAGS -lSDL2_image
	make -j -C ./obj_dir -f Vmcu.mk Vmcu
	cp scramble.txt obj_dir/rom.txt

galaxy:

