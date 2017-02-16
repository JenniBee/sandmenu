all: rm-elf sandmenu.elf

include $(KOS_BASE)/Makefile.rules

OBJS = sandmenu.o

KOS_LOCAL_CFLAGS = -I$(KOS_BASE)/addons/zlib
	
clean:
	-rm -f sandmenu.elf $(OBJS)

dist:
	-rm -f $(OBJS)
	$(KOS_STRIP) sandmenu.elf
	
rm-elf:
	-rm -f sandmenu.elf

sandmenu.elf: $(OBJS) 
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $@ $(KOS_START) $^ -lpng -lz -lm $(KOS_LIBS)

wfont.o: wfont.bin
	$(KOS_BASE)/utils/bin2o/bin2o $< wfont $@

run: sandmenu.elf
	$(KOS_LOADER) $<