K = int(input())

signs = input().split()
result=[None]*K

ops = {
    '>' : lambda x,y:x>y,
    '<' : lambda x,y:x<y
}

stack = list(range(10))

rsp = 0

def stack_init():
    global stack
    stack = list(range(10))

def rsp_set(rcx, rsp):
    rsp = rsp+1 if signs[rcx-1] == '<' else rsp-1

def setting(result:list, stack:list, rcx:int, back:bool):
    # 0 <= rcx < K
    if rcx >= K or rcx <0:
        raise Exception
    rsp_set(rcx, rsp)
    for i, tmp in enumerate(stack, start=rsp):
        if ops[signs[rcx-1]](result[rcx-1], tmp):
            result[rcx]=tmp
            stack.remove(tmp)
            log = [i, tmp]
            back = False
            break
    else:
        stack.insert(log[0],log[1])
        setting(result, stack, rcx-1, back)

