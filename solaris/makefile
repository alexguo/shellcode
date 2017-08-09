AS=nasm
OUTPUT=bin
EXT=bin
all: 
  $(AS) -f$(OUTPUT) sh32.asm -osh.$(EXT)
  $(AS) -f$(OUTPUT) cmd32.asm -ocmd.$(EXT)
  $(AS) -f$(OUTPUT) rs32.asm -ors.$(EXT)
  $(AS) -f$(OUTPUT) bs32.asm -obs.$(EXT)
  disasm -b32 -fc sh.bin >sh32.h
  disasm -b32 -fc cmd.bin >cmd32.h
  disasm -b32 -fc rs.bin >rs32.h
  disasm -b32 -fc bs.bin >bs32.h
clean:
  rm -rf *.bin *.obj *.o  