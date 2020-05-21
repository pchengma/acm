package go

type SSH struct {
	Ip      string
	User    string
	Cert    string
	Port    int
	session *ssh.Session
	client  *ssh.Client
}
