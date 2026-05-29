/**
 * @param {number[]} nums
 * @return {number}
 */
var minElement = function(nums) {
    let mini = Infinity;
    for(let i=0; i<nums.length; i++){
        let x = nums[i];
        let sum = 0;
        while(x > 0){
            let rem = x%10;
            sum += rem;
            x = Math.floor(x/10);
        }
        if(mini > sum) mini = sum;
    }
    return mini;
};