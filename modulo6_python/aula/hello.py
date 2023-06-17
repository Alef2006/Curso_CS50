from cs50 import get_string

resposta=get_string("Qual o seu nome?")
print(f"Hello,{resposta}")


count=0;

while count<=10:
    print(f"count is {count}")
    count+=1

for i in range(10):
    print(f"i is {i}")
    