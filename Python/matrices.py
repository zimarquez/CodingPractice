# Ismael Marquez, im6549

def Dot(vec1, vec2):
    result = 0
    i = 0
    for entry in vec1:
        result += entry * vec2[i]
        i += 1
    return result
            
def Cross(vec1, vec2):
    if len(vec1) == 2:
        a = vec1[0] * vec2[1]
        b = vec1[1] * vec2[0]
        return b-a
    if len(vec1) == 3:
        a = vec1[0] * vec2[1]
        b = vec1[1] * vec2[0]
        
        c = vec1[2] * vec2[0]
        d = vec1[0] * vec2[2]
        
        e = vec1[1] * vec2[2]
        f = vec1[2] * vec2[1]
        result = [(e-f),(c-d),(a-b)]
        return result
    return -1
    
L1 = [0,0,1]
L2 = [1,0,0]
print("Dot: ", Dot(L1,L2))
print("Cross: ", Cross(L1,L2))

        