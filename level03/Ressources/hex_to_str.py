p = [
        0x757c7d51,
        0x67667360,
        0x7b66737e,
        0x33617c7d
]

for h in p:
    a = bytearray.fromhex(hex(h)[2:]).decode()
    print(a[::-1], end='')
print()

