import requests
from bs4 import BeautifulSoup
import urllib.parse

def get_song_lyrics(query):
    # Encode query for URL
    search_query = urllib.parse.quote(query + " lyrics")
    url = f"https://www.google.com/search?q={search_query}"

    # Set headers to mimic a real browser
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                      "AppleWebKit/537.36 (KHTML, like Gecko) "
                      "Chrome/91.0.4472.124 Safari/537.36"
    }

    response = requests.get(url, headers=headers)

    if response.status_code != 200:
        print("Error fetching data from Google")
        return None

    soup = BeautifulSoup(response.text, "html.parser")

    # Extract search snippets (Google may change structure over time)
    snippets = soup.find_all("span")
    for s in snippets[:20]:
        text = s.get_text(strip=True)
        if text:
            print(text)

# Example usage
get_song_lyrics("Imagine by John Lennon")
