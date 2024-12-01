import pyautogui
import time

# Simulate pressing the Win + E keys to open "This PC" (File Explorer)
pyautogui.hotkey('win', 'e')

# Wait for "This PC" to open (you may need to adjust the delay)
time.sleep(2)

# Simulate pressing Ctrl + L to focus on the address bar
pyautogui.hotkey('ctrl', 'l')

# Type 'D:\\Yolov5' in the address bar
pyautogui.typewrite('D:\\Yolov5')

# Press Enter to search in the address bar
pyautogui.press('enter')

# Wait for the search results to appear (adjust the delay if needed)

# Select the first search result (This will vary based on your search results)
pyautogui.press('down')  # Move down to select the first result
pyautogui.press('enter')  # Open the selected folder

# Wait for the folder to open (adjust the delay if needed)
time.sleep(2)

# Open the Command Prompt in the opened folder
pyautogui.hotkey('ctrl', 'l') # Simulate right-click in File Explorer
time.sleep(1)  # Wait for the context menu to open

# Simulate pressing 'W' (for 'Open in Windows Terminal') if available in the context menu

# Or simulate pressing 'C' (for 'Open in Command Prompt) if Windows Terminal is not available
# pyautogui.typewrite('c')

# Wait for the Command Prompt (or Windows Terminal) to open


pyautogui.hotkey('ctrl', 'l')
pyautogui.typewrite('cmd')
pyautogui.press('enter')
time.sleep(5)
# Simulate typing the 'activate' command in the Command Prompt
pyautogui.typewrite('env\\Scripts\\activate')
pyautogui.press('enter')
#time.sleep(5)

pyautogui.typewrite('cd yolov5')
pyautogui.press('enter')

# Run the Python script
pyautogui.typewrite('python detect1.py --weights yolov5n.pt --conf 0.25 --img-size 640 --source 1')
pyautogui.press('enter')
# You may need to add a delay here to allow the script to run before closing the Command Prompt
time.sleep(5)

