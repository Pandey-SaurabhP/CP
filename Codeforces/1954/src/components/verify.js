import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './Verify.css'; // Import CSS file for styling

function Verify() {
    const [pendingIssues, setPendingIssues] = useState([]);
    const [searchQuery, setSearchQuery] = useState('');

    useEffect(() => {
        fetchPendingIssues();
    }, []);

    const fetchPendingIssues = async () => {
        try {
            const response = await axios.get('http://localhost:3001/get_pending');
            setPendingIssues(response.data);
        } catch (error) {
            console.error('Error fetching pending issues:', error);
        }
    };

    const handleStatusChange = async (id, newStatus) => {
        try {
            await axios.post('http://localhost:3001/update_status', { id, status: newStatus });
            fetchPendingIssues();
        } catch (error) {
            console.error('Error updating status:', error);
        }
    };

    const handleSearchInputChange = (event) => {
        setSearchQuery(event.target.value);
    };

    // Filter pending issues based on search query
    const filteredIssues = pendingIssues.filter(issue =>
        issue.issue.toLowerCase().includes(searchQuery.toLowerCase())
    );

    return (
        <div>
            <h2>Pending Issues</h2>
            <input
                type="text"
                placeholder="Search..."
                value={searchQuery}
                onChange={handleSearchInputChange}
            />
            <ul className="pending-issues-list">
                {filteredIssues.map(issue => (
                    <li key={issue._id} className="pending-issue-item">
                        <p><strong>Author:</strong> {issue.author}</p>
                        <p><strong>Issue:</strong> {issue.issue}</p>
                        <p><strong>Room ID:</strong> {issue.room_id}</p>
                        <p><strong>Status:</strong> 
                            <select
                                value={issue.status}
                                onChange={(e) => handleStatusChange(issue._id, e.target.value)}
                            >
                                <option value="Active">Active</option>
                                <option value="Done">Done</option>
                            </select>
                        </p>
                    </li>
                ))}
            </ul>
        </div>
    );
}

export default Verify;
