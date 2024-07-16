N = int(input())

data = list()
stack = dict()
rdi = list()

for i in range(N):
    data.append(input())

for i in range(N):
    for rsp in range(len(data[i])):
        if data[i][rsp] in stack:
            stack[data[i][rsp]] += 10**(len(data[i])-1-rsp)
        else:
            stack[data[i][rsp]] = 10**(len(data[i])-1-rsp)
            
rdi = list(stack.values())
rdi.sort(reverse = True)

rcx = 9
rax =0
for i in range(len(rdi)):
    rax += rcx*rdi[i]
    rcx-=1
    
print(rax)
