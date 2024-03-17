from django.shortcuts import render
import re
routes = {
    '^(\?.*|$)': 'main.html',
    '^game(\/.*$|\?.*|$)': 'game.html',
    '^login(\/.*$|\?.*|$)': 'login.html',
    '^tournament(\/.*$|\?.*|$)': 'tournament.html',
    '^about(\/.*$|\?.*|$)': 'about.html',
    '^users(\/.*$|\?.*|$)': 'profile-detail.html',
    '^livechat(\/.*$|\?.*|$)': 'livechat.html',
    '^pvp(\/.*$|\?.*|$)': 'pvp.html',
    '^match(\/.*$|\?.*|$)': 'match.html',
    '^score(\/.*$|\?.*|$)': 'score.html',
    '^finish-match(\/.*$|\?.*|$)': 'finish-match.html',
    '^ai(\/.*$|\?.*|$)': 'ai.html',
}


def get_requested_file(url: str, routes: dict) -> str:
    for route_pattern in routes.keys():
        regex_match = re.match(route_pattern, url)
        if regex_match is not None:
            import sys
            print(route_pattern, url, regex_match, file=sys.stderr)
            return routes[route_pattern]
    return "error-404.html"


def home(request, url):
    page = get_requested_file(url, routes)
    return render(request, "index.html", {'page_requested': f"static/pages/{page}"})
