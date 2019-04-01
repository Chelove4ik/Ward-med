import pygame
import serial

from excel_reader import list_patients
from time import clock as clck

a = clck()
b = clck()
c = clck()

num_br, num_bez = int(input()), int(input())

bracelet = serial.Serial(f'COM{num_br}')
bezel = serial.Serial(f'COM{num_bez}')

if not bracelet.isOpen():
    bracelet.open()
if not bezel.isOpen():
    bezel.open()

running = True
pygame.init()

size = width, height = 1200, 630
black = pygame.Color('black')

myfont = pygame.font.SysFont('comicsansms', 23)  # Impact

pulse = myfont.render('Пульс', 1, pygame.Color('black'))
kgr = myfont.render('КГР', 1, pygame.Color('black'))
eeg = myfont.render('ЭЭГ', 1, pygame.Color('black'))

BPM = myfont.render(None, 1, black)
GSR = myfont.render(None, 1, black)
EEG = myfont.render(None, 1, black)

screen = pygame.display.set_mode(size)
screen.fill((255, 255, 255))

lst = [
    ((0, 70), (width, 70)),
    ((0, 140), (width, 140)),
    ((0, 210), (width, 210)),
    ((0, 280), (width, 280)),
    ((0, 350), (width, 350)),
    ((0, 420), (width, 420)),
    ((0, 490), (width, 490)),
    ((0, 560), (width, 560)),

    ((200, 0), (200, height)),
    ((320, 0), (320, height)),
    ((390, 0), (390, height)),

    ((500, 0), (500, height)),
    ((610, 0), (610, height)),
    ((720, 0), (720, height))
    # radio mobite
]


def lines():
    [pygame.draw.line(screen, (110, 110, 110), start, end, 2) for start, end in lst]


clock = pygame.time.Clock()
fps = 30

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    screen.fill((255, 255, 255))
    lines()

    for num, tpl in enumerate(list_patients):
        name = myfont.render(tpl[0], 1, black)
        age = myfont.render(tpl[1], 1, black)
        sex = myfont.render(tpl[2], 1, black)
        diagnosis = myfont.render(tpl[3], 1, black)

        screen.blit(name, (10, num * 70 + 17))
        screen.blit(age, (220, num * 70 + 17))
        screen.blit(sex, (330, num * 70 + 17))
        screen.blit(diagnosis, (750, num * 70 + 17))

    screen.blit(pulse, (410, 17))
    screen.blit(kgr, (530, 17))
    screen.blit(eeg, (645, 17))

    val = bracelet.readline().decode('cp1251').split('\r\n')[0].split()
    val_b = bezel.readline().decode('cp1251').split('\r\n')[0].split()
    # print(val)

    if clck() - a >= 5 and val[0] == 'BPM':
        BPM = myfont.render(val[1], 1, black)
        a = clck()
    if clck() - b >= 5 and val[0] == 'GSR':
        GSR = myfont.render(val[1], 1, black)
        b = clck()
    if clck() - c >= 5 and val_b[0] == 'EEG':
        EEG = myfont.render(val_b[1], 1, black)
        c = clck()

    screen.blit(BPM, (410, 70 + 17))
    screen.blit(GSR, (530, 70 + 17))
    screen.blit(EEG, (645, 70 + 17))

    # bracelet.readline().decode('utf-8').split('\r\n')[0]

    pygame.display.flip()
    clock.tick(fps)
