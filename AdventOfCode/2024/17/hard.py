values = [2,4,1,3,7,5,4,7,0,3,1,5,5,5,3,0][::-1]
queue = list(range(8))

for index in range(len(values)):
    print(f"index: {index+1} of {len(values)}; queue: {len(queue)}")
    valid = []

    for value in queue:
        a = value
        b = a % 8
        b = b ^ 3
        c = a // (1 << b)
        b = b ^ 5
        b = b ^ c
        if b % 8 == values[index]:
            valid.append(value)
    next_level = []
    for v in valid:
        for i in range(8):
            next_level.append(v * 8 + i)

    queue = next_level

print(min(valid))