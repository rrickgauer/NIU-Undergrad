import pysftp
import json
import os.path
import getpass

def createConfigFile():

    host = input('host: ')
    username = input('username: ')
    password = getpass.getpass(prompt='password: ')
    directory = input('directory: ')
    file = input('file: ')
    data = {
        "ftp": {
            "host": host,
            "username": username,
            "password": password
        },

        "directory": directory,
        "file": file
    }

    with open('.config.json', 'w') as outfile:
        json.dump(data, outfile)

def getConfigData():
    dataFile = open('.config.json')
    data = json.load(dataFile)
    dataFile.close()
    return data

def getFtpConnection(data):
    cnopts = pysftp.CnOpts()
    cnopts.hostkeys = None
    sftp = pysftp.Connection(host=data['ftp']['host'], username=data['ftp']['username'], password=data['ftp']['password'], cnopts=cnopts)

    return sftp

# create config file if it does not exist
if not os.path.exists('.config.json'):
    createConfigFile()

data = getConfigData()
sftp = getFtpConnection(data)


# change directory
sftp.getcwd()
sftp.chdir(data['directory'])

# upload file
sftp.put(data['file'], preserve_mtime=True)

# execute make command
cmd = 'cd ' + data['directory'] + '; make clean; make;'
sftp.execute(cmd)

# close connection
sftp.close()
print('File uploaded.')
