import socket
import time
import os

# IRC configuration
server = "irc.irccloud.com"  # Replace with your IRC server
channel = "#sailesh-turing-test"  # Replace with your channel
botnick = "TempBot"  # Choose a nickname for your bot

# Function to get CPU temperature (Linux-specific)
def get_cpu_temp():
    try:
        temp = os.popen("vcgencmd measure_temp").readline()
        return temp.replace("temp=", "").replace("'C\n", "")
    except:
        return "Unable to get CPU temperature"

# Connect to the IRC server
irc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
irc.connect((server, 6697))  # 6667 is the standard IRC port

# Send user authentication and join the channel
irc.send(bytes("USER " + botnick + " " + botnick + " " + botnick + " :TempBot\n", "UTF-8"))
irc.send(bytes("NICK " + botnick + "\n", "UTF-8"))
time.sleep(5)  # Wait for the server to register the bot
irc.send(bytes("JOIN " + channel + "\n", "UTF-8"))

while True:
    # Get CPU temperature and send it to the channel every hour
    cpu_temp = get_cpu_temp()
    irc.send(bytes("PRIVMSG " + channel + " :CPU Temperature: " + cpu_temp + "\n", "UTF-8"))
    time.sleep(3600)  # Sleep for 1 hour