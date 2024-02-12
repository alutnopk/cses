s = input()
prevc = ""
count = 0
max_count = 0
for ch in s:
    if ch == prevc:
        count += 1
    else:
        max_count = max_count if max_count >= count else count
        count = 1
    prevc = ch

max_count = max_count if max_count >= count else count
print(max_count)