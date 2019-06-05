#!/usr/bin/env python3.5

import os
import binascii
import codecs

with open("packet", "rb") as file:
    buffer = file.read()
    # buffer = binascii.hexlify(buffer)
file.close()
key = [0x32, 0x36, 0x13, 0x92, 0xa5, 0x5a, 0x27, 0xf3]

# for element in buffer:
#     for i, val in enumerate(key):
#         if(i == len(key)):
#             i = 0
#     result = hex(bool(element) != bool(val))
#     print(result)

print(buffer, "\n")
write_here_buffer = []
counter = 0
for element in buffer:
    write_here_buffer.append(element ^ key[counter%8])
    counter+=1
# write_here_buffer = [hefor element in write_here_buffer]

print(buffer)
# writing decrypted data to file
with open("write_here", "wb") as file:
    for element in write_here_buffer:
        file.write(bytes(element))
file.close()
