def URLify(url, length):
    return url.rstrip().replace(" ", "%20")
            
tests = [ ["Mr John Smith    ", 13], ["much ado about nothing      ", 22] ]
for test in tests:
    print(URLify(test[0], test[1]))