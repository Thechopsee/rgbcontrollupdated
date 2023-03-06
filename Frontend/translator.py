print("hello")
with open("Frontend/index.html", "r") as file:
    file_data = file.readlines()
file.close()

my_array = []
for item in file_data:
    my_array.append('client.println("' + item.strip() + '");')

with open("log.txt", "w") as file:
    file.write('\n'.join(my_array))
file.close()
