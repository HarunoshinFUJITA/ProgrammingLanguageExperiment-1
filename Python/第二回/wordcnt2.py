'''演習1-2 ワードカウント'''

with open('wordcnt2.py', 'r') as f:
    lines = f.readlines()

# 行数はリストの長さを見ればわかる
line_counts = len(lines)

# 以下に演習の答えを書いていくこと
word_counts = 0
char_counts = 0

for l in lines:
    char_counts += len(l)
    words = l.split()
    word_counts += len(words)

print('lines: ', line_counts)
print('words: ', word_counts)
print('characters: ', char_counts)