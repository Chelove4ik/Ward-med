import pygame

# import serial

# num_br, num_bez = int(input()), int(input())
#
# bracelet = serial.Serial(f'COM{num_br}')
# bezel = serial.Serial(f'COM{num_bez}')

running = True
pygame.init()

size = width, height = 1200, 600

myfont = pygame.font.SysFont('comicsansms', 23)  # Impact

screen = pygame.display.set_mode(size)
screen.fill((255, 255, 255))

lst = [
    ((0, 70), (width, 70)),
    ((0, 140), (width, 140)),
    ((200, 0), (200, height)),
    ((320, 0), (320, height)),
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

    name = myfont.render('Фамилия      И.О', 1, pygame.Color('black'))
    age = myfont.render('Возраст', 1, pygame.Color('black'))
    sex = myfont.render('Пол', 1, pygame.Color('black'))

    screen.blit(name, (10, 17))
    screen.blit(age, (220, 17))
    screen.blit(sex, (330, 17))

    pygame.display.flip()
    clock.tick(fps)
