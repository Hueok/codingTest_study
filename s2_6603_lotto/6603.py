import itertools

def print_cases(query):
    for s in itertools.combinations(query[1:], 6):
        print(' '.join(list(s)))

while True:
    query = list(input().split())
    if query == ['0']:
        break
    print_cases(query)
    print()
    
