# First time writing Python code in quite awhile. Let's see how this goes.

# Project 2 for Applied Cryptography
# Robert Maloy
# 9 February 2019

# We're going to declare our strings! What a joyous miracle, no bloody arrays of strings!
string1="9d6e7a7d155295eef8512c087da56084f743aaa9985ee3848a768c3484d2e2ea6b3f4e5483f61 2d55987ff4782f360bd4809bab835fa1e65f8459c6814472508cc7f72241ee70c34fb9e7c8c4c 246132845d5d73d070de99a73efe1e9ee627ea8f4aaae147087cce6c8cd08813f81caf9d71204 86b16"
string2="8968617d0f1b97e5ee51280f3aec72caf106bdb48d44a68291339e35db86b6f56f2140548bf25 3cd1593e8498baa34ba4f02fda070e25075b04387681b473610cc7f75614ae21a3efb8672d85d 3e2031cc5b5a23c17ad9cda334ef10"
targetString="866e786a0042d4abf21e305c35ad65c1b542bbbe8f55b3848032c6359fc3e2e96b21421196a10 7c90195a30896bc61f54906abae35fd196fb1519b2d1206320b892b7c7719e60e37b697738c07 76292a9c5d132ac66a8bd1a728bb5882e629"

# testing variables
enc = 'the of and a to in is be that was he for it with as his I on have at by not they this had are but from or she'

def stringxor(msg1, msg2):
    if len(msg1) > len(msg2):
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(msg1[:len(msg2)], msg2)])
    else:
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(msg1, msg2[:len(msg1)])])

txt = stringxor(string1, string2)
print(txt)

txtcomp = stringxor(enc, txt)
print
print(enc)
print(txtcomp)
