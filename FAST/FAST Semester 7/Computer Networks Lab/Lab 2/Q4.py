import sys
import struct

byte_order = sys.byteorder
print(f"{byte_order} endian is being used by my machine")

short_int = 0x3412
packed_data = struct.pack('h', short_int)
print(f"Short Integer Packed (byte by byte): {list(packed_data)}")

