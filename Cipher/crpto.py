shift_table = [1, 1, 2, 2,
               2, 2, 2, 2,
               1, 2, 2, 2,
               2, 2, 2, 1]

initial_permutation_table = [58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7]

permutation_1 = [57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
                 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
                 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
                 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4]

permutation_2 = [14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
                 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
                 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]

expansion_permutation_table = [32, 1, 2, 3, 4, 5,
                               4, 5, 6, 7, 8, 9,
                               8, 9, 10, 11, 12, 13,
                               12, 13, 14, 15, 16, 17,
                               16, 17, 18, 19, 20, 21,
                               20, 21, 22, 23, 24, 25,
                               24, 25, 26, 27, 28, 29,
                               28, 29, 30, 31, 32, 1]

permutation_table = [16, 7, 20, 21, 29, 12, 28, 17,
                     1, 15, 23, 26, 5, 18, 31, 10,
                     2, 8, 24, 14, 32, 27, 3, 9,
                     19, 13, 30, 6, 22, 11, 4, 25]

index_list = [
    [[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
     [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]],
    [[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]],
    [[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]],
    [[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]],
    [[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]],
    [[12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]],
    [[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]],
    [[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]]
]
final_permutation_table = [40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25]


def apply_xor(a_binary, b_binary):
    answer = ""
    for i in range(len(a_binary)):
        if(a_binary[i] == b_binary[i]):
            answer = answer+"0"
        else:
            answer = answer+"1"
    return answer


def hexadec_binary(message):
    binary_list = {'0': "0000",
                   '1': "0001",
                   '2': "0010",
                   '3': "0011",
                   '4': "0100",
                   '5': "0101",
                   '6': "0110",
                   '7': "0111",
                   '8': "1000",
                   '9': "1001",
                   'A': "1010",
                   'B': "1011",
                   'C': "1100",
                   'D': "1101",
                   'E': "1110",
                   'F': "1111"}
    binary_eq = ""
    for i in range(len(message)):
        binary_eq = binary_eq + binary_list[message[i]]
    return binary_eq


def binary_hexadec(message):
    binary_list = {"0000": '0',
                   "0001": '1',
                   "0010": '2',
                   "0011": '3',
                   "0100": '4',
                   "0101": '5',
                   "0110": '6',
                   "0111": '7',
                   "1000": '8',
                   "1001": '9',
                   "1010": 'A',
                   "1011": 'B',
                   "1100": 'C',
                   "1101": 'D',
                   "1110": 'E',
                   "1111": 'F'}
    hex = ""
    for i in range(0, len(message), 4):
        ch = ""
        ch = ch+message[i]
        ch = ch+message[i+1]
        ch = ch+message[i+2]
        ch = ch+message[i+3]
        hex = hex+binary_list[ch]
    return hex


def binary_decimal(message):
    decimal, i = 0, 0
    while(message != 0):
        dec = message % 10
        decimal = decimal+dec*pow(2, i)
        message = message//10
        i += 1
    return decimal


def decimal_binary(num):
    binary_equivalent = bin(num).replace("0b", "")
    if(len(binary_equivalent) % 4 != 0):
        div = len(binary_equivalent) / 4
        div = int(div)
        counter = (4*(div+1))-len(binary_equivalent)
        for i in range(0, counter):
            binary_equivalent = '0'+binary_equivalent
    return binary_equivalent


def shift_left(key, shift_counter):
    s = ""
    for i in range(shift_counter):
        for j in range(1, len(key)):
            s = s+key[j]
        s = s+key[0]
        key = s
        s = ""
    return key


def initial_permutation(plain_text, initial_permutation_table, number_of_bits):
    permutation = ""
    for i in range(0, number_of_bits):
        permutation = permutation+plain_text[initial_permutation_table[i]-1]
    return permutation


def encrypt(message, key):
    print("Encryption")
    message = hexadec_binary(message)
    message = initial_permutation(message, initial_permutation_table, 64)
    key = hexadec_binary(key)
    key = initial_permutation(key, permutation_1, 56)
    l = key[0:28]
    r = key[28:56]
    left = message[0:32]
    right = message[32:64]
    key_from_pc2_bin = []
    key_from_pc2_hex = []
    for k in range(16):
        l = shift_left(l, shift_table[k])
        r = shift_left(r, shift_table[k])
        combine_key = l+r
        round_key = initial_permutation(combine_key, permutation_2, 48)
        key_from_pc2_bin.append(round_key)
        key_from_pc2_hex.append(binary_hexadec(round_key))
        key_from_pc2_bin = key_from_pc2_bin[::-1]
        key_from_pc2_hex = key_from_pc2_hex[::-1]
    print()
    print("Iteration: ", end='\t\t')
    print("The subkey used in this Iteration:")
    for j in range(16):
        right_expand = initial_permutation(right, expansion_permutation_table, 48)
        answer_xor_func = apply_xor(right_expand, key_from_pc2_bin[j])
        index_list_str = ""
        for i in range(0, 8):
            row = binary_decimal(int(answer_xor_func[i*6]+answer_xor_func[i*6+5]))
            column = binary_decimal(int(answer_xor_func[i*6+1]+answer_xor_func[i*6+2]+answer_xor_func[i*6+3]+answer_xor_func[i*6+4]))
            val = index_list[i][row][column]
            index_list_str = index_list_str+decimal_binary(val)
        index_list_str = initial_permutation(index_list_str, permutation_table, 32)
        result = apply_xor(left, index_list_str)
        left = result
        if(j != 15):
            left, right = right, left
        print('\t', str(j+1).zfill(2), end='\t\t\t\t\t\t')
        print(key_from_pc2_hex[j])
    combine = left+right
    encrypted_text = initial_permutation(combine, final_permutation_table, 64)
    return encrypted_text


def add_padding(message):
    if(len(message) % 16 != 0):
        print("The Text entered is not 64 bits long, it needs padding")
        for i in range(abs(16-(len(message) % 16))):
            message = message+'0'
    else:
        print("The text is exactly 64 bits long, it doesn't need padding")
    return(message)
# Main Function, i.e. Driver Code
print("Enter the text that needs to be encrypted:")
plain_text = input()
plain_text = add_padding(plain_text)
print("The revised text after padding: ", plain_text)
print("Enter the Key to be used to perform the encryption:")
key = input()
key = add_padding(key)
print("The revised Key after padding: ", key)
encrypted_text = binary_hexadec(encrypt(plain_text, key))
print("The message after encrypting it using the given key is: ", encrypted_text)

