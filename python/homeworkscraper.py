from bs4 import BeautifulSoup
import urllib2
import os
#from slackclient import SlackClient
import time
import sys
import subprocess


# BOT_NAME = 'homeworkbot'
# SLACK_BOT_TOKEN = 'xoxb-51409230321-Uw2aWVtKVdfxJro8TUFl7ohg'
# BOT_ID = 'U1HC16S9F'
# AT_BOT = '<@' + BOT_ID + '>:'
# EXAMPLE_COMMAND = 'start'
# PAUSE = 'pause'
# NEXTSONG = 'next'
# PLAY = 'play'
# STOP = 'stop'
#
# slack_client = SlackClient('xoxb-51409230321-Uw2aWVtKVdfxJro8TUFl7ohg')
# process = 1
#
# def handle_command (command, channel):
#     global process
#     response = "Not sure what you mean. Use the *" + EXAMPLE_COMMAND + \
#                "* command with numbers, delimited by spaces."
#     if command.startswith(EXAMPLE_COMMAND):
#         response = "I am currently playing - "
#         process = subprocess.Popen(['pianobar'])
#     if command.startswith(PAUSE):
#         response = "Okay, paused"
#         process.communicate('m')
#     if command.startswith(PLAY):
#         response = "Okay, I will play"
#         process.communicate('p')
#     if command.startswith(STOP):
#         response = "Pandora Ended"
#         process.communicate('q')
#     if command.startswith(NEXTSONG):
#         response = "Shifting to next song"
#         process.communicate('n')
#     slack_client.api_call("chat.postMessage", channel=channel, text=response, as_user=True)
#
#
# def parse_slack_output(slack_rtm_output):
#     output_list = slack_rtm_output
#     if output_list and len(output_list) > 0:
#         for output in output_list:
#             if output and 'text' in output and AT_BOT in output['text']:
#                 return output['text'].split(AT_BOT)[1].strip().lower(), \
#                        output['channel']
#     return None, None
#
# if __name__ == '__main__':
#     READ_WEBSOCKET_DELAY = 1
#     if slack_client.rtm_connect():
#         print ("Navbot is a go")
#         while True:
#             command, channel = parse_slack_output(slack_client.rtm_read())
#             if command and channel:
#                 handle_command(command,channel)
#             time.sleep(READ_WEBSOCKET_DELAY)
#     else:
#         print "Connection invalid"


reader = urllib2.urlopen('http://cs61a.org')
html = reader.read()
soup = BeautifulSoup(html,'html.parser')
dates = soup.find_all('td', {"class" : "resource-name"})
for x in dates:
    print(x.next_sibling())
