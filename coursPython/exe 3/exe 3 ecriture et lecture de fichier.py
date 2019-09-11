a = 5
b = 2.83
c = 67
f = open('Monfichier', 'w')
f.write(str(a))
f.write(str(b))
f.write(str(c))
f.close()
f = open('Monfichier', 'r')
print(f.read())
f.close()
