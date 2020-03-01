def binary_search(input_array, value):
    low = 0
    hig = len(input_array)-1
    while(low<=hig):
        mid = int((low+hig)/2)
        if (input_array[mid]== value):
            return mid
        elif (input_array[mid]< value):
            low = mid +1
        else:
            hig = mid-1
    return -1

test_list = [1,3,9,11,15,19,29]
print (binary_search(test_list, int(input("Enter a number to FIND "))))
"""print (binary_search(test_list, test_val2))"""