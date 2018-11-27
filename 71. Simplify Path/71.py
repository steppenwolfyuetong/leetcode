class Solution:
    # @param {string} path
    # @return {string}
    def simplifyPath(self, path):
        result = []
        pathList = path.split('/')
        for letter in pathList:
            if letter:
                if letter == '..':
                    try:
                        result.pop()
                    except:
                        result = []
                elif letter != '.':
                    result.append(letter)
        return '/'+'/'.join(result)
        
print(Solution.simplifyPath(Solution,"/a/./b/../../c/"))