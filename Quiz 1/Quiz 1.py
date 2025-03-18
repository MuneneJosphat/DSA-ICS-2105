

def removeDuplicates(nums):
    if not nums:
        return 0

#Intialize the slow pointer(Keeps track position of the next unique elem)
    slow = 0

#Iterete through the array with the fast pointer(iterates through the array)
    for fast in range(1,len(nums)):
        if nums[fast] != nums[slow]:  #This checks if the next and previous elems are not equal,the slow pointer moves forward
            slow+=1
            nums[slow]=nums[fast] #updates method at the slow pointer position
    return slow+1 #returns the new position

nums = [1,2,2,3,3,4,5,6,7,7,7,8,9]
new_length = removeDuplicates(nums)
print("New length: ",new_length)
print("Modified array: ",nums[:new_length])