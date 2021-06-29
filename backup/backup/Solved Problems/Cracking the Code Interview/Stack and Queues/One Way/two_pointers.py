## Time Complexity: O(min(N,M)) Space Complexity: O(1)
def one_way(str1, str2):
    
    n, m = len(str1), len(str2)
    
    if abs(n - m) > 1:
        return False
    
    if n > m:
        str1, str2 = str2, str1

    if n == m:
        flg = False
        for i in range(n):
            if str1[i] != str2[i]:
                
                if flg is True:
                    return False
                
                flg = True
                
        return True
    
    if n != m:
        i, j = 0, 0
        while i < n and j < m:
            if str1[i] != str2[j]:
                if i != j:
                    return False
                j += 1
            else:
                i += 1
                j += 1
                
        return True
    
tests = [ 
            ## Same Length
            ['pales','pales'], 
            ['bales', 'pales'], 
            ['bales', 'paaas'], 
            ## Insert
            ['pales','paless'], 
            ['pales', 'pasles'], 
            ['bale', 'paaas'],
            ## Removal
            ['pales','pale'], 
            ['pales', 'ples'], 
            ['bale', 'bl']
        ] 
for test in tests:
    print(one_way(test[0], test[1]))
    