import requests
from bs4 import BeautifulSoup


#obtain data
data = requests.get('https://pokemondb.net/move/generation/1#')

#load data into bs4
soup = BeautifulSoup(data.text, 'html.parser')

databoard = soup.find('table', {'class': 'data-table block-wide'})
tbody = databoard.find('tbody')

outfile = open('pokemonMoves.txt', 'w')


for tr in tbody.find_all('tr'):
    moveName = tr.find_all('td')[0].find_all('a')[0].text.strip()
    pokeType = tr.find_all('td')[1].find_all('a')[0].text.strip()
    moveCate = tr.find_all('td')[2].attrs['data-sort-value']
    power    = tr.find_all('td')[3].text.strip()
    accuracy = tr.find_all('td')[4].text.strip()
    pp       = tr.find_all('td')[5].text.strip()
    
    
    #print(moveName, pokeType, moveCate, power, accuracy, pp)
    
    moveName = moveName.replace(chr(32), '_')
    
    outfile.write(moveName)
    if len(moveName) <= 7:
        outfile.write('\t')
    outfile.write('\t')
    
    outfile.write(pokeType)
    if len(pokeType) <= 7:
        outfile.write('\t')
    outfile.write('\t')
    
    outfile.write(moveCate)
    if len(moveCate) <= 7:
        outfile.write('\t')
    outfile.write('\t')
    
    if pp == '\u2014':
        pp = '0'
    outfile.write(pp)
    outfile.write('\t')
    
    if power == '\u2014':
        power = '0'
    outfile.write(power)
    outfile.write('\t')
    
    if accuracy == '\u2014':
        accuracy = '0'
    outfile.write(accuracy)
    outfile.write('\n')
    
    
outfile.close()
