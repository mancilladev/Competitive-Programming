def solve(s, note):
    notes = ['DO', 'DO#', 'RE', 'RE#', 'MI', 'FA', 'FA#', 'SOL', 'SOL#', 'LA', 'LA#', 'SI']
    s = int(s)
    return notes[(notes.index(note) - s)%len(notes)]

s, note = input().split()
print(solve(s, note))
