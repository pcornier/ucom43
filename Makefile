
.PHONY: cpp

clean:
	-rm top.out
	-rm vfd.o vfd.vpi

trace:
	rm -rf ./obj_dir
	verilator --trace -Wall --cc mcu.v --exe tb.cpp -CFLAGS -I/usr/include/SDL2 -CFLAGS -g -LDFLAGS -lSDL2 -LDFLAGS -lSDL2_image
	make -j -C ./obj_dir -f Vmcu.mk Vmcu
	cp rom.txt obj_dir
	cp -r obj_dir ~/

cpp:
	rm -rf ./obj_dir
	verilator -Wall --cc mcu.v --exe tb.cpp -CFLAGS -I/usr/include/SDL2 -CFLAGS -g -LDFLAGS -lSDL2 -LDFLAGS -lSDL2_image
	make -j -C ./obj_dir -f Vmcu.mk Vmcu
	cp rom.txt obj_dir
	cp -r obj_dir ~/
