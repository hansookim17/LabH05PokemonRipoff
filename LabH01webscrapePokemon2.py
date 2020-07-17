import requests
from bs4 import BeautifulSoup


#obtain data
data = requests.get('https://pokemondb.net/pokedex/all')

#load data into bs4
soup = BeautifulSoup(data.text, 'html.parser')

databoard = soup.find('table', {'class': 'data-table block-wide'})
tbody = databoard.find('tbody')

outfile = open('pokemonRoster.txt','w')

n = list(range(1034))
i = 0
for tr in tbody.find_all('tr'):

    n[i] = tr.find_all('td')[0].find_all('span')[2].text.strip()
    if n[i] == n[i - 1]:
        continue
    
    #FIND pokemonName
    pokemonName = tr.find_all('td')[1].find_all('a')[0].text.strip()
    pokemonName = pokemonName.replace('\xe9', 'e')
    pokemonName = pokemonName.replace(chr(32), '_')
    
    #FIND pokemonType
    pokemonType = ['NoneT','NoneT']   
    if len(tr.find_all('td')[2].find_all('a')) == 1:
        pokemonType[0] = tr.find_all('td')[2].find_all('a')[0].text.strip()
        pokemonType[1] = 'NoneT'
    else: 
        pokemonType[0] = tr.find_all('td')[2].find_all('a')[0].text.strip()
        pokemonType[1] = tr.find_all('td')[2].find_all('a')[1].text.strip()
    
    #FIND stats
    statHP      = tr.find_all('td')[4].text.strip()
    statAtk     = tr.find_all('td')[5].text.strip()
    statDef     = tr.find_all('td')[6].text.strip()
    statSpAtk   = tr.find_all('td')[7].text.strip()
    statSpDef   = tr.find_all('td')[8].text.strip()
    statSpeed   = tr.find_all('td')[9].text.strip()
    
    #WRITE pokemonName
    outfile.write(pokemonName)
    if len(pokemonName) <= 7:
        outfile.write('\t')
    outfile.write('\t')
    
    #WRITE pokemonType
    
    outfile.write(pokemonType[0])
    if len(pokemonType[0]) <= 7:
        outfile.write('\t')
    outfile.write('\t')
    
    outfile.write(pokemonType[1])
    if len(pokemonType[1]) <= 7:
        outfile.write('\t')
    outfile.write('\t')
        
    #WRITE stats
    outfile.write(statHP)
    outfile.write('\t')
    
    outfile.write(statAtk)
    outfile.write('\t')
    
    outfile.write(statDef)
    outfile.write('\t')
    
    outfile.write(statSpAtk)
    outfile.write('\t')
    
    outfile.write(statSpDef)
    outfile.write('\t')
    
    outfile.write(statSpeed)
    outfile.write('\n')
    
    #if len(tr.find_all('td')[2].find_all('a')) == 1:
     #   print(pokemonName, pokemonType[0], statHP, statAtk, statDef, statSpAtk, statSpDef, statSpeed, i)
    #else:
     #   print(pokemonName, pokemonType[0], pokemonType[1], statHP, statAtk, statDef, statSpAtk, statSpDef, statSpeed, i)
    
    i = i + 1
outfile.close()