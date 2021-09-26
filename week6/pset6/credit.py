# Detect wheter a credit card is real of fake, and if real, return the creditor name it is (i.e. VISA)

import cs50

cardNumber = get_int("Please enter a card number: ")






# Ask for card number
    # if card number is not long/too long
        # min/ max card number
        # reject
    # if card number is right size
        # Luhn's algo
            # if Luhn's algo fails
                # print phony card!
            # else
                # return creditor