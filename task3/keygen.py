import random
import string


def gen_key():
    chars = string.ascii_uppercase + string.ascii_lowercase + string.digits
    key = ''
    for i in range(0, 3):
        key += ''.join(random.choice(chars) for _ in range(5))
        key += '-'
    key = key[:-1]
    return key


def check_key(key):
    block0 = key[0:5]
    block1 = key[6:11]
    block2 = key[12:17]
    a = 0
    b = 0
    c = 0
    d = 0

    for i in block0:
        if ord(i) < 91:
            a += ord(i)
        else:
            b += ord(i)
    if (a >> 2) & 0xf == (b + 1) & 0x7:
        c += a
    else:
        d += b

    for i in block1:
        if ord(i) < 91:
            a += ord(i)
        else:
            b += ord(i)
    if (a >> 2) & 0xf == (b + 1) & 0x7:
        c += a
    else:
        d += b

    for i in block2:
        if ord(i) < 91:
            a += ord(i)
        else:
            b += ord(i)
    if (a >> 2) & 0xf == (b + 1) & 0x7:
        c += a
    else:
        d += b

    return c == d and c != 0


if __name__ == '__main__':
    # Подбор корректного ключа перебором (для проверки работоспособности).
    found = 0
    while found < 5:
        k = gen_key()
        if check_key(k):
            print(k)
            found += 1
