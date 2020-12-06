
import cImage
import sys

def negativeImage(sourceImg):
    newImg = cImage.EmptyImage(sourceImg.getWidth(),sourceImg.getHeight())

    for x in range(sourceImg.getWidth()):
        for y in range(sourceImg.getHeight()):
            p = sourceImg.getPixel(x, y)
            #greenP = cImage.Pixel(0, p.getGreen(), 0)
            negativeP = cImage.Pixel(255-p.getRed(), 255-p.getGreen(), 255-p.getBlue())
            newImg.setPixel(x, y, negativeP)

    return newImg

def grayScale(sourceImg):
    newImg = cImage.EmptyImage(sourceImg.getWidth(),sourceImg.getHeight())

    for x in range(sourceImg.getWidth()):
        for y in range(sourceImg.getHeight()):
            p = sourceImg.getPixel(x, y)
            intensity = (p.getRed() + p.getGreen() + p.getBlue()) // 3
            #intensity = p.getRed()
            grayP = cImage.Pixel(intensity, intensity, intensity)
            newImg.setPixel(x, y, grayP)

    return newImg

def verticalFlip(sourceImg):
    newImage = cImage.EmptyImage(sourceImg.getWidth(),sourceImg.getHeight())
    for x in range(sourceImg.getWidth()):
        for y in range(sourceImg.getHeight()):
            p = sourceImg.getPixel(x, y)
            newImage.setPixel(sourceImg.getWidth()-1-x, y, p)

    return newImage
    

def enlarge(sourceImg, factor):
    newImg = cImage.EmptyImage(factor*sourceImg.getWidth(), factor*sourceImg.getHeight())

    for x in range(sourceImg.getWidth()):
        for y in range(sourceImg.getHeight()):
            p = sourceImg.getPixel(x, y)
            for i in range(factor):
                for j in range(factor):
                    newImg.setPixel(factor*x+i, factor*y+j, p)
              
    return newImg

def main():
    fileName = sys.argv[1]

    imageToProcess = cImage.FileImage(fileName)

    print('What would you like to do?')
    print('1) Negagive')
    print('2) Grey scale')
    print('3) Double the size')
    print('4) Vertical Flip')

    choice = input('Please pick an operation (1-4):')
    
    if choice=='1':
        newImg = negativeImage(imageToProcess)
    elif choice=='2':
        newImg = grayScale(imageToProcess)
    elif choice=='3':
        newImg = enlarge(imageToProcess, 2)
    else:
        newImg = verticalFlip(imageToProcess)

    if choice!='3':
        myImageWin = cImage.ImageWin('Image Processing', 2*imageToProcess.getWidth()+10,\
                                imageToProcess.getHeight() )
    else:
        myImageWin = cImage.ImageWin('Image Processing', 3*imageToProcess.getWidth()+10,\
                                     imageToProcess.getHeight()*2 )

    imageToProcess.draw(myImageWin)

    newImg.setPosition(imageToProcess.getWidth()+10,0)

    newImg.draw(myImageWin)

    myImageWin.exitOnClick()

main()

        
    
