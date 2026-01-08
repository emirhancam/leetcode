int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) 
{
    *returnSize = temperaturesSize;

    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    
    int top = -1;  // Stack pointer
    
    for (int i = 0; i < temperaturesSize; i++) 
    {
        // Mevcut sıcaklık, stack'teki sıcaklıklardan büyükse
        while (top >= 0 && temperatures[stack[top]] < temperatures[i]) 
        {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        
        stack[++top] = i;
    }
    
    free(stack);
    return result;
}
