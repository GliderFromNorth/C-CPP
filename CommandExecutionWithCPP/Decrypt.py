########################
'''
Vivek kumar
Input :- 1st Argumetn "Key" , 2nd Argumetn - "Encrypt  File Path"
Output	:- Decript the Files at the same Location
https://pycryptodome.readthedocs.io/en/latest/src/installation.html
Key Must be 16 chr
Module required 
Python 3.6.8
1> pycryptodome  [pip install pycryptodome]
2> base64
3> sys
Syntex :-  python PythonScriptFileName key EncryptFilePath
Example - python Decript.py qwsecretpassword c:\filename.txt.encrypted
OutputFilePath - c:\filename.txt.decrypted
'''
#########################

from Crypto import Random
from Crypto.Cipher import AES
import binascii
import base64
import sys
BS = 16
pad = lambda s: bytes(s + (BS - len(s) % BS) * chr(BS - len(s) % BS), 'utf-8')
unpad = lambda s : s[0:-ord(s[-1:])]

class AESCipher:

    def __init__( self, key ):
        self.key = bytes(key, 'utf-8')

    def decrypt( self, enc ):
        enc = base64.b64decode(enc)
        iv = enc[:16]
        cipher = AES.new(self.key, AES.MODE_CBC, iv )
        return unpad(cipher.decrypt( enc[16:] )).decode("utf-8")

if __name__ == "__main__":
	cipher = AESCipher(sys.argv[1])#('qwsecretpassword')
	EncryptedFilePath=open(sys.argv[2],"rb")#(c:\filename.txt)
	chunk = EncryptedFilePath.read()
	decrypted = cipher.decrypt(chunk)
	bytes = binascii.a2b_hex(''.join(decrypted))
	f_read=open(sys.argv[2]+".decrypted","wb")
	f_read.write((bytes))