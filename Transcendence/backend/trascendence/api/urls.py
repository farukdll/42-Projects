from django.urls import path
from trascendence.api.views import UserView
from trascendence.api.views import AuthView
from trascendence.api.views import InteractionsView
from trascendence.api.views import TorunamentsView
from trascendence.api.views import Uploads
from trascendence.api.views import profile_views
from trascendence.api.views import MatchesView

# Write decorator to restrict http methods for requests
# auth_redirect -> 42/oauth -> auth/token/code -> page

urlpatterns = [

    # Authentication
    path('auth/sign-in/42', AuthView.sign_in_42),
    path('auth/sign-in', AuthView.sign_in),
    path('auth/sign-up', AuthView.sign_up),
    path('auth/token', AuthView.verify_token),
    path('auth/token/refresh', AuthView.refresh_token),

    # Interactions
    path('interacts/friends', InteractionsView.get_friends),
    path('interacts/friends/status/<username>', InteractionsView.check_friendship_status),
    path('interacts/friends/add', InteractionsView.add_friend),
    path('interacts/friends/delete/<username>', InteractionsView.delete_friend),
    path('interacts/invitations', InteractionsView.get_invitations),
    path('interacts/invitations/<invite_code>/accept', InteractionsView.accept_invitation),
    path('interacts/invitations/<invite_code>/delete', InteractionsView.decline_invitation),
    path('interacts/blacklist', InteractionsView.get_blacklist),
    path('interacts/blacklist/add', InteractionsView.add_blacklist),
    path('interacts/blacklist/<target_username>/delete', InteractionsView.remove_blacklist),
    path('interacts/blacklist/search/<username>', InteractionsView.check_in_blacklist),

    # Tournaments
    path('tournaments/create', TorunamentsView.create_tournament),
    path('tournaments/invitations', TorunamentsView.get_tournament_invitations),
    path('tournaments/invitations/<invitationcode>', TorunamentsView.get_tournament_invitation),
    path('tournaments/invitations/<invitationcode>/accept', TorunamentsView.accept_tournamet),
    path('tournaments/invitations/<invitationcode>/delete', TorunamentsView.decline_tournament),
    path('tournaments/user/<username>', TorunamentsView.get_tournaments_for_user),
    path('tournaments/', TorunamentsView.get_tournaments),
    path('tournaments/<tournamentcode>', TorunamentsView.get_tournament),
    path('tournaments/<tournamentcode>/players', TorunamentsView.get_tournament_players),
    path('tournaments/<tournamentcode>/matches', TorunamentsView.get_tournament_matches),
    path('tournaments/<tournamentcode>/<username>/delete', TorunamentsView.remove_tournament_user),
    path('tournaments/start/<tournamentcode>', TorunamentsView.start_tournament),
    path('tournaments/<tournamentcode>/next-match', TorunamentsView.get_next_match),

    # Matches
    path('matches/submit', MatchesView.submit_matches_for_users),
    path('matches/submit/<matchcode>', MatchesView.submit_planned_match),
    path('matches/code/<matchcode>', MatchesView.get_planned_match),
    path('matches/player/verify', MatchesView.verify_playcode),
    path('matches/<username>', MatchesView.get_matches_for_user),
    path('matches/<user1>/<user2>', MatchesView.get_matches_for_users),
    
    # Uploads
    path('uploads/upload', Uploads.upload_file),
    path('uploads/delete/<file>', Uploads.delete_file),

    # Profile
    path('profile/update', profile_views.update_profile),
    path('profile/<username>', profile_views.get_user_profile),

    # Search User
    path('users/search/<username>', UserView.search_user)
]
