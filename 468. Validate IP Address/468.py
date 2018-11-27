class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if self.isValidIPv4(IP):
            return "IPv4"
        elif self.isValidIPv6(IP):
            return "IPv6"
        else:
            return "Neither"

    def isValidIPv4(self, IP):
        groups = IP.split('.')
        if len(groups) == 4:
            for group in groups:
                for ch in group:
                    if not ch.isdigit():
                        return False
                if len(group) == 0:
                    return False
                if int(group) < 0 or int(group) > 255:
                    return False
                if group[0] == '0' and len(group) > 1:
                    return False
            return True
        else:
            return False

    def isValidIPv6(self, IP):
        groups = IP.split(':')
        digits = set("0123456789abcdefABCDEF")
        if len(groups) == 8:
            for group in groups:
                for ch in group:
                    if ch not in digits:
                        return False
                if len(group) == 0 or len(group) > 4:
                    return False
            return True
        else:
            return False

if __name__ == "__main__":
    s = Solution()
    IP = "172.16.254.1"
    print(s.validIPAddress(IP))
    IP = "172.16.254.01"
    print(s.validIPAddress(IP))
    IP = "2001:0db8:85a3:0000:0000:8a2e:0370:7334"
    print(s.validIPAddress(IP))
    IP = "2001:db8:85a3:0:0:8A2E:0370:7334"
    print(s.validIPAddress(IP))
    IP = "2001:0db8:85a3::8A2E:0370:7334"
    print(s.validIPAddress(IP))
