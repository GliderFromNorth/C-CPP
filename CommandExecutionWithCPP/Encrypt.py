########################
'''
Vivek Kumar
Input :- 1st Argumetn "Key" , 2nd Argumetn - "File Path"
Output	:- Encrypt the Files at the same location
https://pycryptodome.readthedocs.io/en/latest/src/installation.html
Key Must be 16 chr
Module required 
Python 3.6.8
1> pycryptodome  [pip install pycryptodome]
2> base64
3> sys
Syntex :-  python PythonScriptFileName key FilePath
Example - python Encrypt.py qwsecretpassword c:\filename.txt
OutputFilePath - c:\filename.txt.encrypted
'''
#########################
import base64
from Crypto import Random
from Crypto.Cipher import AES
import sys
BS = 16
pad = lambda s: bytes(s + (BS - len(s) % BS) * chr(BS - len(s) % BS), 'utf-8')
unpad = lambda s : s[0:-ord(s[-1:])]

class AESCipher:

    def __init__( self, key ):
        self.key = bytes(key, 'utf-8')

    def encrypt( self, FilePath ): 
        inputfile = open(FilePath,"rb")
        chunk = inputfile.read().hex()
        chunk = (chunk)
        raw = pad(chunk)
        iv = Random.new().read( AES.block_size )
        cipher = AES.new(self.key, AES.MODE_CBC, iv )
        return base64.b64encode( iv + cipher.encrypt( raw ) )

if __name__ == "__main__":
	cipher = AESCipher(sys.argv[1])#KEY('qwsecretpassword')
	FilePath = cipher.encrypt(sys.argv[2])#FilePath(c:\filename.txt)
	f_write=open(sys.argv[2]+".encrypted","wb")
	f_write.write(FilePath)