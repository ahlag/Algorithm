def split(word): 
    return [char for char in word] 

def URLify(url, length):
    
    back = len(url) - 1
    for cur in range(length -1, -1, -1):
        if url[cur] != ' ':
            break
        
    while cur >= 0:
        if url[cur] != ' ':
            url[back] = url[cur]
            back -= 1
        else:
            url[back-2:back+1] = '%20' 
            back -= 3
        cur -= 1
    return ''.join(url)
            
yo