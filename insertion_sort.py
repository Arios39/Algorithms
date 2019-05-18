# insertion sort

def insertionSort(A):
    for i in range(1, len(A)):

        key = A[i]

        j = i - 1
        while j >= 0 and key < A[j]:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key



arr = [4, 5, 12, 15, 14, 10, 8, 18, 19, 20]
insertionSort(arr)
print("Sorted array is:")
for i in range(len(arr)):
    print(arr[i])
