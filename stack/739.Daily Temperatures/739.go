func dailyTemperatures(temperatures []int) []int {
    n := len(temperatures)
    result := make([]int, n)  
    stack := []int{}          
    
    for i := 0; i < n; i++ {
        // Mevcut sıcaklık, stack'teki sıcaklıklardan büyükse
        for len(stack) > 0 && temperatures[stack[len(stack)-1]] < temperatures[i] {
            prevIndex := stack[len(stack)-1]
            stack = stack[:len(stack)-1]  // pop
            result[prevIndex] = i - prevIndex
        }
        
        stack = append(stack, i)
    }
    
    return result
}
