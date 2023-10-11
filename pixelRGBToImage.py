import sys
import numpy as np
from PIL import Image

imageMode = sys.argv[1]
imageSize = (int(sys.argv[2]), int(sys.argv[3]))

# Read the band pixel values from their respective files
convolvedRed = np.loadtxt("imageRedConvolved.txt", dtype=int)
convolvedGreen = np.loadtxt("imageGreenConvolved.txt", dtype=int)
convolvedBlue = np.loadtxt("imageBlueConvolved.txt", dtype=int)

# Combine the individual bands into RGB pixels
convolvedPixelsRGB = list(zip(convolvedRed, convolvedGreen, convolvedBlue))

# Create the new image and populate it with the RGB pixel values
newImage = Image.new(imageMode, imageSize)
newImage.putdata(convolvedPixelsRGB)

# Save the newly created image
newImage.save("convolvedImage.jpg")