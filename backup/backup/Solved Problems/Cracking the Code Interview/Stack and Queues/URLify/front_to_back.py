def URLify(url, length):
    
    new_url = ''
    
    for char in url:
        if char == ' ':
            new_url += '%20'
        else:
            new_url += char
            
    return new_url
            
tests = [ ["Mr John Smith    ", 13], ["John Smith ", 10] ]
for test in tests:
    print(URLify(test[0], test[1]))