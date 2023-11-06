array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(len(array)):
    current_idx = i
    for j in range(i+1, len(array)):
        if array[current_idx] > array[j]: current_idx = j
    array[current_idx], array[i] = array[i], array[current_idx]

print(array)