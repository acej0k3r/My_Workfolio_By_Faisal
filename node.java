
public class node {
	int jobId;
	int jobTime;
	node next;
	node(){
		jobId= -1;
		jobTime = -1;
	}
	node(int x, int y){
		jobId = x;
		jobTime = y;
		next = null;
	}
	
	void setId(int x) {
		jobId = x;
	}
	void setTime(int x) {
		jobTime = x;
	}
	void setNext(node x) {
		next = x;
	}
	int getId() {
		return jobId;
	}
	int getTime() {
		return jobTime;
	}
	
	node getNext() {
		return this.next;
	}
	
	
}
