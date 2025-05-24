"""Given an array, rotate the array to the right by k steps, where k is non-negative."""

def rotate(nums,k):
    n = len(nums)
    k = k % n #Handles cases where the value of k is greater than the array length

    '''This line below performs the rotation
    nums[-k:]--gives the last k elems of the array
    nums[:-k]--gives the other elems excludimg the last k elems
     nums[:]--modifies array in place'''
    nums[:]=nums[-k:]+nums[:-k]

nums = [1,2,3,4,5,6,7]
k = 2
rotate(nums,k)
print(nums)